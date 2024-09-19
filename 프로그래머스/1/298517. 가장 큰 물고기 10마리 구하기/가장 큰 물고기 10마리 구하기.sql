select id, length
from fish_info
order by ifnull(length,10) desc
limit 10
