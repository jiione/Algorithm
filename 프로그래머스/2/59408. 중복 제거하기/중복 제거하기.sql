-- 코드를 입력하세요
SELECT count(distinct name) as count
from animal_ins
where name is not null