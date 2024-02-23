SELECT car_id, max(if('2022-10-16' between start_date and end_date, '대여중','대여 가능')) as AVAILABILITY
from car_rental_company_rental_history
group by car_id
order by car_id desc;
