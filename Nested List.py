#nested if 
#displaying name of second last students using nested if
#also in ascending order

if __name__ == '__main__':
    students=[]
    for _ in range(int(input())):
        name = input()
        score = float(input())
        students.append([name,score])
    grade_result=set(score for _,score in students)
    grade_result=sorted(list(grade_result))
    second_lowest_grade = grade_result[1]
    result=[]
    for student in students:
        for score in student:
            if score==second_lowest_grade:
                result.append(student[0])
    result.sort()
    for student in result:
        print(student)