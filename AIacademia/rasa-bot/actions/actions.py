import os
import sys
import django
import requests
from rasa_sdk import Action, Tracker
from rasa_sdk.executor import CollectingDispatcher
from typing import Any, Text, Dict, List
from fuzzywuzzy import process
from rasa_sdk.events import SessionStarted, ActionExecuted

# Add the project directory to the PYTHONPATH
project_path = os.path.abspath(os.path.join(os.path.dirname(__file__), '../../'))
sys.path.append(project_path)

# Set up the Django environment
os.environ.setdefault('DJANGO_SETTINGS_MODULE', 'AIacademia.settings')
django.setup()

# Import Django models
from academia_app.models import School, Course

class ActionFetchCourses(Action):

    def name(self) -> Text:
        return "action_fetch_courses"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        school_name = next(tracker.get_latest_entity_values("school_name"), None)

        if not school_name:
            all_courses = Course.objects.all()[:5]  # Fetch first 5 courses as examples
            example_courses_list = ", ".join([course.name for course in all_courses])
            dispatcher.utter_message(text=f"Here are some example courses offered: {example_courses_list}. Please specify a school for more detailed information.")
            return []

        schools = School.objects.all()
        school_names = [school.name for school in schools]

        best_match, score = process.extractOne(school_name, school_names)

        if score < 70:
            dispatcher.utter_message(text=f"Sorry, I couldn't find a school named {school_name}. Did you mean {best_match}? Please specify the correct school name.")
            return []

        try:
            school = School.objects.get(name=best_match)
            courses = Course.objects.filter(school=school)

            if courses:
                courses_list = ", ".join([course.name for course in courses])
                dispatcher.utter_message(text=f"The courses offered in {best_match} are: {courses_list}.")
            else:
                dispatcher.utter_message(text=f"Sorry, I couldn't find any courses for {best_match}.")
        except School.DoesNotExist:
            dispatcher.utter_message(text=f"Sorry, I couldn't find the school named {best_match}.")

        return []

class ActionSessionStart(Action):
    def name(self) -> Text:
        return "action_session_start"

    async def run(self, dispatcher, tracker, domain):
        events = [SessionStarted()]
        events.append(ActionExecuted("action_listen"))
        dispatcher.utter_message(text="Welcome! How can I help you today?")
        return events

class ActionKeepAlive(Action):
    def name(self) -> Text:
        return "action_keep_alive"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:
        return []

class ActionWebSearch(Action):
    def name(self) -> Text:
        return "action_web_search"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:
        
        query = tracker.latest_message.get('text')
        search_url = "https://api.duckduckgo.com/"
        params = {
            "q": query,
            "format": "json",
            "no_html": 1,
            "skip_disambig": 1
        }

        response = requests.get(search_url, params=params)
        response.raise_for_status()
        search_results = response.json()

        if "AbstractText" in search_results and search_results["AbstractText"]:
            dispatcher.utter_message(text=f"Here's what I found: {search_results['AbstractText']}")
        elif "RelatedTopics" in search_results and search_results["RelatedTopics"]:
            top_result = search_results["RelatedTopics"][0]
            if "Text" in top_result and "FirstURL" in top_result:
                dispatcher.utter_message(text=f"Here's what I found: {top_result['Text']} ({top_result['FirstURL']})")
            else:
                dispatcher.utter_message(text="Sorry, I couldn't find any information on that.")
        else:
            dispatcher.utter_message(text="Sorry, I couldn't find any information on that.")

        return []

if __name__ == "__main__":
    django.setup()
    ActionFetchCourses()
    ActionSessionStart()
    ActionKeepAlive()
    ActionWebSearch()
