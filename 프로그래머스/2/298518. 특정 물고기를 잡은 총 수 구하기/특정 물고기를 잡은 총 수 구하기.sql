select count(*) as fish_count
from fish_info as f join fish_name_info as n
on f.fish_type = n.fish_type
where n.fish_name in ('BASS', 'SNAPPER')
