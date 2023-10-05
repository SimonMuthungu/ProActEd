from django.shortcuts import render
from django.http import HttpResponse, JsonResponse
import joblib
from django.views.decorators.csrf import csrf_protect


# Create your views here.

def login(request):
    return render(request, "academia_app/login.html")


def student_page(request):
    return render(request, "academia_app/student_page.html")


def admin_page(request):
    # Defining school data with departments

    school_data = [
        {'name': 'SCI', 'departments': ['computer science', 'IT'], 'cs':['Computer Science', 'cct'], 'IT':['ict', 'it']},
        {'name': 'SOE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SOP', 'departments': ['Pharmacology and Pharmacognosy', 'Pharmaceutical chemistry and analysis'], 'ph&ph':['']},
        {'name': 'SPA', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SOM', 'departments': ['Bachelor of Medicine and Surgery', 'Bachelor of Medicine in Family and Emergency Medicine', 'Bachelor of Medicine in General Surgery']},
        {'name': 'SON', 'departments': ['Community Health Nursing', 'Midwifery Nursing', 'Medical Surgical Nursing', 'Nursing Education, leadership & Research'], 'CHN': ['BSc. Nursing with IT']},
        {'name': 'SDSS', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SPDS', 'departments': ['Botany', 'Chemistry', 'Physics & Material Science', 'Zoology'],'Bot':['BSc. Botany', 'Bsc. Ethnobotany & Medicinal Plants', 'BSc. Sciences(Botany)']},
        {'name': 'SAFE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SASS', 'departments': ['Arts and Design', 'History and Archeology', '', 'Department W', 'Department V']},
        {'name': 'SBE', 'departments': ['Accounting & Finance', 'Business Administration', 'Business Entrepreneurship', 'Hotel & Institution Management', 'Travel & Tourism']},
        {'name': 'SPCD', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SMSAS', 'departments': ['Pure and Applied Mathematics', 'Statistics and Actuarial Science'], 'PAM': ['BSc. Mathematics & Business Studies', 'Maths and economics', 'Maths and Computer Science', 'Mathematical Sciences'], 'SAS':['BSC. Applied Statistics','Actuarial Science', 'Diploma Actuarial Science', 'Cert in Basic Statistics']}
        
        # Add data for other schools similarly
]
    context = {'school_data': school_data}
    return render(request, 'academia_app/admin_page.html', context)


# form to manually input probabilities for testing purposes
def predict_view(request):
    return render(request, "academia_app/predict.html")



# view to calculate probabilities
def predict_data(request):
    # Load the trained model
    model = joblib.load(r'C:\Users\Simon\proacted\ProActEd\Projoo\trained_logistic_regression_model(5000).joblib')

    if request.method == 'POST':
        # Get the values of the form fields
        lessons_attended = request.POST['lessons_attended']
        aggregate_points = request.POST['aggregate_points']
        csrf_token = request.POST['csrfmiddlewaretoken']

        # Get input data (e.g., from request) and making predictions using the values
        input_data = [lessons_attended, aggregate_points]

        # Make predictions using the loaded model
        predictions = model.predict(input_data)

        # For demonstration purposes, let's return a response with the received data
        response_text = f"Lessons Attended: {lessons_attended}, Aggregate Points: {aggregate_points}"
    return HttpResponse(response_text)


    # Return predictions as JSON response
    # return JsonResponse({'predictions': predictions.tolist()})