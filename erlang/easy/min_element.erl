-module(min_element).

-spec min_element(Nums :: [integer()]) -> integer().
min_element([]) ->
  0;
min_element([H | T]) ->
  calculate_sum(H) + min_element(T).

-spec calculate_sum(Num :: integer()) -> integer().
calculate_sum(0) ->
  0;
calculate_sum(Num) ->
  Num rem 10 + calculate_sum(Num div 10).
