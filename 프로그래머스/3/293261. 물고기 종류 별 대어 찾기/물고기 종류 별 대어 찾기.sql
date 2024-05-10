select fi.id, ni.fish_name, fi.length
from fish_info as fi join fish_name_info as ni
on fi.fish_type = ni.fish_type
where fi.fish_type in(
    select fish_type
    from fish_info
    group by fish_type
    having length = max(length)
)
order by fi.id