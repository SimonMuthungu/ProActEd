from django.shortcuts import render
from django.http import HttpResponse

# Create your views here.
def login(request):
    return render(request, "academia_app/login.html")
def student_page(request):
    return render(request, "academia_app/student_page.html")
def admin_page(request):
    return render(request, "academia_app/admin_page.html")


    school_data = [
        {'name': 'SCI', 'departments': ['computer science', 'IT'], 'cs':['Computer Science', 'cct'], 'IT':['ict', 'it']},
        {'name': 'SOE', 'departments': ['Department X', 'Department Y', 'Department Z', 'Department W', 'Department V']},
        {'name': 'SOP', 'departments': ['Pharmacology and Pharmacognosy', 'Pharmaceutical chemistry and analysis'], 'ph&ph':[''], 'Phca': ['']}
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
    ]
        
        # Add data for other schools similarly

