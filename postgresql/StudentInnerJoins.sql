--SELECT * FROM courses;
--SELECT * FROM students;
--SELECT * FROM enrollments;

-- this query gets the student name and course name of all courses
-- that the student is taking

SELECT 
	students.student_name,
	courses.name
FROM students 
INNER JOIN enrollments ON enrollments.student_id = students.id
INNER JOIN courses ON courses.id = enrollments.course_id;

--INSERT INTO enrollments(student_id, course_id, grade) VALUES(1, 4, 'A');