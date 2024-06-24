from typing import Any, Text, Dict, List
from rasa_sdk import Action, Tracker
from rasa_sdk.executor import CollectingDispatcher
from bot_data.models import MasenoInfo
import requests
from bs4 import BeautifulSoup

DUCKDUCKGO_API_URL = "https://api.duckduckgo.com/"

    def search_duckduckgo(query):
        params = {
            'q': query,
            'format': 'json',
            'pretty': 1
        }
        response = requests.get(DUCKDUCKGO_API_URL, params=params)
        data = response.json()
        return data['AbstractURL']

    def get_webpage_content(url):
        response = requests.get(url)
        soup = BeautifulSoup(response.text, 'html.parser')
        return soup
class ActionInformProgram(Action):

    def name(self) -> Text:
        return "action_inform_program"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        programs = MasenoInfo.objects.using('bot_db').filter(category='Program Information').all()

        if programs:
            response = "\n".join([f"Detail: {program.detail}, Additional Info: {program.additional_info}" for program in programs])
        else:
            response = "I couldn't find any program information in the database."

            # Check Maseno University website
            query = "Program Information site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Program Information site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "I couldn't find any program information online. Kindly rephrase your question"

        dispatcher.utter_message(text=response)
        return []

class ActionInformFeeStructure(Action):

    def name(self) -> Text:
        return "action_inform_fee_structure"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        fee_structure = MasenoInfo.objects.using('bot_db').filter(category='Fee Structure').first()

        if fee_structure:
            response = f"Category: {fee_structure.category}, Detail: {fee_structure.detail}, Additional Info: {fee_structure.additional_info}"
        else:
            response = "searching..."

            # Check Maseno University website
            query = "Fee Structure site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Fee Structure site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "I couldn't find any fee structure information online. Kindly rephrse your question"

        dispatcher.utter_message(text=response)
        return []

class ActionInformContactInformation(Action):

    def name(self) -> Text:
        return "action_inform_contact_information"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        contact_info = MasenoInfo.objects.using('bot_db').filter(category='Contact Information').all()

        if contact_info:
            response = "\n".join([f"Detail: {info.detail}, Additional Info: {info.additional_info}" for info in contact_info])
        else:
            response = "I couldn't find any contact information in the database."

            # Check Maseno University website
            query = "Contact Information site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Contact Information site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "Kindly rephrase your question."

        dispatcher.utter_message(text=response)
        return []

class ActionInformGeneralInformation(Action):

    def name(self) -> Text:
        return "action_inform_general_information"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        general_info = MasenoInfo.objects.using('bot_db').filter(category='General Information').all()

        if general_info:
            response = "\n".join([f"Detail: {info.detail}, Additional Info: {info.additional_info}" for info in general_info])
        else:
            response = "I couldn't find any general information in the database."

            # Check Maseno University website
            query = "General Information site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "General Information site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "Rephrase your question kindly"

        dispatcher.utter_message(text=response)
        return []

class ActionInformUniversityManagement(Action):

    def name(self) -> Text:
        return "action_inform_university_management"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        university_management = MasenoInfo.objects.using('bot_db').filter(category='University Management').all()

        if university_management:
            response = "\n".join([f"Detail: {management.detail}, Additional Info: {management.additional_info}" for management in university_management])
        else:
            response = "I couldn't find any information about the university management in the database."

            # Check Maseno University website
            query = "University Management site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "University Management site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "Rephrase your question."

        dispatcher.utter_message(text=response)
        return []

class ActionInformUniversityCouncil(Action):

    def name(self) -> Text:
        return "action_inform_university_council"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        university_council = MasenoInfo.objects.using('bot_db').filter(category='University Council').all()

        if university_council:
            response = "\n".join([f"Detail: {council.detail}, Additional Info: {council.additional_info}" for council in university_council])
        else:
            response = "I couldn't find any information about the university council in the database."

            # Check Maseno University website
            query = "University Council site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "University Council site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "I couldn't find any information about the university council online."

        dispatcher.utter_message(text=response)
        return []

        joining_instructions = MasenoInfo.objects.using('bot_db').filter(category='Joining Instructions').all()

        if joining_instructions:
            response = "\n".join([f"Detail: {instruction.detail}, Additional Info: {instruction.additional_info}" for instruction in joining_instructions])
        else:
            response = "I couldn't find any joining instructions in the database."

            # Check Maseno University website
            query = "Joining Instructions site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Joining Instructions site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = "Rephrase your question kindly, so that I can understand."

        dispatcher.utter_message(text=response)
        return []

class ActionInformPrograms(Action):

    def name(self) -> Text:
        return "action_inform_programs"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        programs = MasenoInfo.objects.using('bot_db').filter(category='Program Types').all()

        if programs:
            response = "\n".join([f"Detail: {program.detail}, Additional Info: {program.additional_info}" for program in programs])
        else:
            response = "I couldn't find any program types information in the database."

            # Check Maseno University website
            query = "Program Types site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Program Types site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = ("Some of the known programs are these:\n"
                            "- Certificate programs\n"
                            "- Diploma programs\n"
                            "- Degree programs\n"
                            "- Masters programs\n"
                            "- Doctrate programs\n"
                            "- Phd programs available too.")

        dispatcher.utter_message(text=response)
        return []

class ActionInformKnownHotels(Action):

    def name(self) -> Text:
        return "action_inform_known_hotels"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        known_hotels = MasenoInfo.objects.using('bot_db').filter(category='Known Hotels').all()

        if known_hotels:
            response = "\n".join([f"Detail: {hotel.detail}, Additional Info: {hotel.additional_info}" for hotel in known_hotels])
        else:
            response = "...searching..."

            # Check Maseno University website
            query = "Known Hotels site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "Known Hotels site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = ("I couldn't find any information about known hotels online."                            "However, here are some known university hostels:\n"
                            "However, here are some known hotels in Maseno Vacinity:\n"
                            "- Mama Farida -> in Nywita\n"
                            "- Mams --> around market\n"
                            "- Caroline Herein --> around Market\n"
                            "- Shamim's  --> in Nyawita\n"
                            "- Mama Ben's --> in Nyawita\n"
                            "- Vet Vibandaski --> on your way to VET hostels")

        dispatcher.utter_message(text=response)
        return []

class ActionInformUniversityHostels(Action):

    def name(self) -> Text:
        return "action_inform_university_hostels"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        university_hostels = MasenoInfo.objects.using('bot_db').filter(category='University Hostels').all()

        if university_hostels:
            response = "\n".join([f"Detail: {hostel.detail}, Additional Info: {hostel.additional_info}" for hostel in university_hostels])
        else:
            response = "searching..."

            # Check Maseno University website
            query = "University Hostels site:maseno.ac.ke"
            data = search_duckduckgo(query)
            if 'RelatedTopics' in data and data['RelatedTopics']:
                response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
            else:
                # Check Kenyadmission website
                query = "University Hostels site:kenyadmission.com"
                data = search_duckduckgo(query)
                if 'RelatedTopics' in data and data['RelatedTopics']:
                    response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])
                else:
                    response = ("I couldn't find any information about university hostels online."                            "However, here are some known places around Maseno University:\n"
                            "However, here are some known university hostels:\n"
                            "- Equator\n"
                            "- Kilimanjaro\n"
                            "- Kit Mikayi\n"
                            "- Nyabundi")

        dispatcher.utter_message(text=response)
        return []

class ActionInformCommunityAroundMaseno(Action):

    def name(self) -> Text:
        return "action_inform_community_around_maseno"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        # Attempt to fetch the information using the DuckDuckGo API
        query = "Community around Maseno University site:kenyadmission.com"
        data = search_duckduckgo(query)

        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            # Check in the database as a fallback
            community_around_maseno = MasenoInfo.objects.using('bot_db').filter(category='Community Around Maseno').all()
            if community_around_maseno:
                response = "\n".join([f"Detail: {community.detail}, Additional Info: {community.additional_info}" for community in community_around_maseno])
            else:
                # Provide a default response with known examples
                response = ("I couldn't find any information about the community around Maseno University at the moment. "
                            "However, here are some known places around Maseno University:\n"
                            "- Maseno Police Station\n"
                            "- Hospitals\n"
                            "- Supermarkets\n"
                            "- Children's Home\n"
                            "- High School\n"
                            "- Primary School\n"
                            "- Maseno Law Courts")

        dispatcher.utter_message(text=response)
        return []

class ActionInformBestDishesHotels(Action):

    def name(self) -> Text:
        return "action_inform_best_dishes_hotels"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        best_dishes_hotels = MasenoInfo.objects.using('bot_db').filter(category='Best Dishes Hotels').all()

        if best_dishes_hotels:
            response = "\n".join([f"Detail: {dish.detail}, Additional Info: {dish.additional_info}" for dish in best_dishes_hotels])
        else:
            response = "I couldn't find any information about the best dishes and hotels."

        dispatcher.utter_message(text=response)
        return []

class ActionInformClubsAround(Action):

    def name(self) -> Text:
        return "action_inform_clubs_around"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        # Attempt to fetch the information using the DuckDuckGo API
        query = "Clubs around Maseno University site:kenyadmission.com"
        data = search_duckduckgo(query)

        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            # Check in the database as a fallback
            clubs_around = MasenoInfo.objects.using('bot_db').filter(category='Clubs Around').all()
            if clubs_around:
                response = "\n".join([f"Detail: {club.detail}, Additional Info: {club.additional_info}" for club in clubs_around])
            else:
                # Provide a default response with examples
                response = ("I couldn't find any information about clubs around Maseno University at the moment. "
                            "However, some known clubs around Maseno University include Tripple T and Red Liquor.")

        dispatcher.utter_message(text=response)
        return []

class ActionInformClubsAndOrganizations(Action):

    def name(self) -> Text:
        return "action_inform_clubs_and_organizations"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        # Attempt to fetch the information using the DuckDuckGo API
        query = "Maseno University clubs and organizations site:kenyadmission.com"
        data = search_duckduckgo(query)

        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            # Check in the database as a fallback
            clubs_and_organizations = MasenoInfo.objects.using('bot_db').filter(category='Clubs and Organizations').all()
            if clubs_and_organizations:
                response = "\n".join([f"Detail: {club.detail}, Additional Info: {club.additional_info}" for club in clubs_and_organizations])
            else:
                # Provide a default response
                response = ("Maseno University has a vibrant student community with various clubs and organizations, including the Students Organization of Maseno University (SOMU). "
                            "Students can participate in academic clubs, sports teams, cultural groups, and more, offering numerous opportunities for personal and professional growth. "
                            "These organizations help students develop leadership skills, network with peers, and engage in community service.")

        dispatcher.utter_message(text=response)
        return []

class ActionInformScholarshipApplication(Action):

    def name(self) -> Text:
        return "action_inform_scholarship_application"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        scholarship_application = MasenoInfo.objects.using('bot_db').filter(category='Scholarship Application').all()

        if scholarship_application:
            response = "\n".join([f"Detail: {scholarship.detail}, Additional Info: {scholarship.additional_info}" for scholarship in scholarship_application])
        else:
            response = "I couldn't find any information about scholarship applications."

        dispatcher.utter_message(text=response)
        return []

class ActionInformAcademicCalendar(Action):

    def name(self) -> Text:
        return "action_inform_academic_calendar"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        query = "Maseno University academic calendar site:kenyadmission.com"
        data = search_duckduckgo(query)

        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            response = ("Maseno University's academic calendar includes important dates for the start and end of semesters, exam periods, holidays, and other academic events. "
                        "For the most up-to-date information, please visit the Maseno University website or contact the administration.")

        dispatcher.utter_message(text=response)
        return []



class ActionInformEducationStyle(Action):

    def name(self) -> Text:
        return "action_inform_education_style"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        query = "Maseno University education style site:kenyadmission.com"
        data = search_duckduckgo(query)

        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            response = ("Maseno University offers a comprehensive education experience combining traditional one-on-one lectures, eCampus for online learning, and various extracurricular activities. "
                        "Our education style is designed to provide a well-rounded experience, preparing students for diverse career paths and personal growth. "
                        "Students have the opportunity to participate in sports, arts, and community service, ensuring a holistic approach to education. "
                        "At Maseno University, you receive an education that is not just about academics but also about personal and professional development.")

        dispatcher.utter_message(text=response)
        return []

class ActionInformCampuses(Action):

    def name(self) -> Text:
        return "action_inform_campuses"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        campuses_info = MasenoInfo.objects.using('bot_db').filter(category='Maseno in Brief').first()

        if campuses_info:
            response = "Maseno University has several campuses: Main Campus in Maseno Township, Kisumu Campus, Odera Akang'o in Siaya County, and the eCampus."
        else:
            response = "I couldn't find any information about the campuses of Maseno University."

        dispatcher.utter_message(text=response)
        return []

class ActionInformDirections(Action):

    def name(self) -> Text:
        return "action_inform_directions"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        directions = MasenoInfo.objects.using('bot_db').filter(category='Maseno in Brief').first()

        if directions:
            # Extracting only the part mentioning campuses
            response = "Directions to Maseno University campuses:\n"
            if "Main Campus" in directions.additional_info:
                response += "Main Campus: Situated in Maseno Township along Kisumu-Busia road, 25 km from Kisumu City and approximately 400 km west of Nairobi, the capital city of Kenya.\n"
            if "Kisumu Campus" in directions.additional_info:
                response += "Kisumu Campus: Located in Kisumu City.\n"
            if "Odera Akang'o" in directions.additional_info:
                response += "Odera Akang'o: Located in Siaya County.\n"
            if "eCampus" in directions.additional_info:
                response += "eCampus: An online campus.\n"
        else:
            response = "I couldn't find any information about directions."

        dispatcher.utter_message(text=response)
        return []

class ActionInformLatestNews(Action):

    def name(self) -> Text:
        return "action_inform_latest_news"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        query = "Maseno University latest news site:maseno.ac.ke"
        data = search_duckduckgo(query)
        
        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            response = "I couldn't find any latest news."

        dispatcher.utter_message(text=response)
        return []

class ActionInformTrendingSchool(Action):

    def name(self) -> Text:
        return "action_inform_trending_school"

    def run(self, dispatcher: CollectingDispatcher,
            tracker: Tracker,
            domain: Dict[Text, Any]) -> List[Dict[Text, Any]]:

        query = "Maseno University latest news site:maseno.ac.ke"
        data = search_duckduckgo(query)
        
        if 'RelatedTopics' in data and data['RelatedTopics']:
            response = "\n".join([topic['Text'] for topic in data['RelatedTopics'][:5]])  # Return the first 5 topics
        else:
            response = "I couldn't find any information about the latest news or trending school."

        dispatcher.utter_message(text=response)
        return []





