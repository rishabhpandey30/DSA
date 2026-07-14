# Write your MySQL query statement bel
select s.user_id , Round(AVG(CASE 
                                when c.action ='confirmed' Then 1.00 
                                else 0 
                            END
),2) as confirmation_rate
from Signups s
left join Confirmations c on s.user_id = c.user_id
group by s.user_id