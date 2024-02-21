-- 코드를 입력하세요
SELECT animal_id, name
from animal_ins
where INTAKE_CONDITION = 'Sick'
order by animal_id