-module(get_sneaky_numbers).

-spec get_sneaky_numbers(Nums :: [integer()]) -> [integer()].
get_sneaky_numbers(Nums) ->
  Map = #{},
  Rs = [],
  get_sneaky_numbers(Nums, Map, Rs).

get_sneaky_numbers([], _, _) ->
  [];
get_sneaky_numbers([H | T], Map, Rs) ->
  case maps:is_key(H, Map) of
    true ->
      NewRs = [H | Rs],
      case length(NewRs) of
        2 ->
          NewRs;
        _ ->
          get_sneaky_numbers(T, Map, NewRs)
      end;
    _ ->
      Map1 = Map#{H => 1},
      get_sneaky_numbers(T, Map1, Rs)
  end.
