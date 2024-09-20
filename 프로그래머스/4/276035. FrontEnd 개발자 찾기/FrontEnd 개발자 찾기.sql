-- 코드를 작성해주세요
select distinct d.id, d.email, d.first_name, d.last_name
from developers d join skillcodes s on s.code = s.code & d.skill_code
where s.category = 'Front End'
order by d.id