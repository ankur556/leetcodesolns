# Write your MySQL query statement below
select t.person_name from queue t where
t.turn=(
select max(t1.turn) from queue t1
where
1000>=ifnull((
    select sum(weight)
    from queue t2
    where t1.turn>=t2.turn
),true)
)