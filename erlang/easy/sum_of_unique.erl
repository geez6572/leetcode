-module(sum_of_unique).

-spec sum_of_unique(Nums :: [integer()]) -> integer().
sum_of_unique(Nums) ->
  Map = #{},
  recur(Nums, Map).

-spec recur(Nums :: [integer()], Map :: map()) -> integer().
recur([], Map) ->
  0;
recur([H | T], Map) ->
  case maps:is_key(H, Map) of
    true ->
      Val = maps:get(H, Map),
      Map1 = Map#{H => Val + 1},
      case Val of
        1 ->
          -H + recur(T, Map1);
        _ ->
          recur(T, Map1)
      end;
    false ->
      Map1 = Map#{H => 1},
      H + recur(T, Map1)
  end.
