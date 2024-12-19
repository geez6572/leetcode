-module(number_of_pairs).

-export([number_of_pairs/1]).

-spec number_of_pairs(Nums :: [integer()]) -> [integer()].
number_of_pairs(Nums) ->
  Map = #{},
  number_of_pairs(Nums, Map).

-spec number_of_pairs(Nums :: [integer()], Map :: map()) -> [integer()].
number_of_pairs([], Map) ->
  maps:fold(fun(_, Val, Acc) ->
               [lists:nth(1, Acc) + Val div 2, lists:nth(2, Acc) + Val rem 2]
            end,
            [0, 0],
            Map);
number_of_pairs([H | T], Map) ->
  case maps:is_key(H, Map) of
    true ->
      Val = maps:get(H, Map),
      Map1 = Map#{H => Val + 1},
      number_of_pairs(T, Map1);
    _ ->
      Map1 = Map#{H => 1},
      number_of_pairs(T, Map1)
  end.
