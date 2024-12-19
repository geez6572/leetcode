-module(create_target_array).

-spec create_target_array(Nums :: [integer()], Index :: [integer()]) -> [integer()].
create_target_array(Nums, Index) ->
  create_target_array([], Nums, Index).

create_target_array(Cur, [], []) ->
  Cur;
create_target_array(Cur, [H1 | T1], [H2 | T2]) ->
  Next = insert_at(Cur, H2, H1),
  create_target_array(Next, T1, T2).

-spec insert_at(Nums :: [integer()], Index :: integer(), Val :: integer()) -> [integer()].
insert_at([], _, Val) ->
  [Val];
insert_at(Nums, 0, Val) ->
  [Val | Nums];
insert_at([H | T], Index, Val) ->
  [H | insert_at(T, Index - 1, Val)].
