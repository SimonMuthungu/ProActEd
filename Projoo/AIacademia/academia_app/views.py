from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def login(request):
    return render(request, "academia_app/login.html")
def student_page(request):
    return render(request, "academia_app/student_page.html")
def admin_page(request):
    return render(request, "academia_app/admin_page.html")

def admin_page(request):
    # Define school data with departments
    school_data = [
        {'name': 'SCI', 'departments': ['computer science', 'IT'], 'cs':['Computer Science', 'cct'], 'IT':['ict', 'it']},
        {'name': 'SOE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SOP', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SPA', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SOM', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SON', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SDSS', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SPDS', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SAFE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SASS', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SBE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SPCD', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SMSAS', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        
        # Add data for other schools similarly
]
    context = {'school_data': school_data}
    return render(request, 'academia_app/admin_page.html', context)
