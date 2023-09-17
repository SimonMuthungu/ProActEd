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
        {'name': 'School 1', 'departments': ['Department A', 'Department B', 'Department C', 'Department D', 'Department E']},
        {'name': 'School 2', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 3', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 4', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 5', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 6', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 7', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 8', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 9', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 10', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 11', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 12', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 13', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 14', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 15', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 16', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 17', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 18', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 19', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'School 20', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        # Add data for other schools similarly
]
    context = {'school_data': school_data}
    return render(request, 'academia_app/admin_page.html', context)
