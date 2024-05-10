select i.ITEm_ID, i.item_name, i.rarity
from ITEM_INFO as i
join ITEM_TREE as t on i.item_id = t.item_id
where t.parent_item_id in(select item_id from item_info
                         where rarity ='RARE')
order by i.item_id desc