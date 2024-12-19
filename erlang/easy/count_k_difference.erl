-module(count_k_difference).

-spec count_k_difference(Nums :: [integer()], K :: integer()) -> integer().
count_k_difference(Nums, K) ->
  Map = #{},
  count_k_difference(Nums, K, Map).

get_value(Key, Map) ->
  case maps:is_key(Key, Map) of
    true ->
      maps:get(Key, Map);
    _ ->
      0
  end.

count_k_difference([], _, _) ->
  0;
count_k_difference([H | T], K, Map) ->
  Val1 = get_value(H - K, Map),
  Val2 = get_value(H + K, Map),
  Val3 = get_value(H, Map),
  NewMap = Map#{H => Val3 + 1},
  Val1 + Val2 + count_k_difference(T, K, NewMap).
