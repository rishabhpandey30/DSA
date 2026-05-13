# Write your MySQL query statement below
select st.student_id, st.student_name, s.subject_name, Count(e.student_id) as attended_exams from Students st cross join Subjects s left join Examinations e on st.student_id = e.student_id
and s.subject_name = e.subject_name
group by student_id, subject_name , student_name
order by st.student_id , s.subject_name