-module(find_center).

-spec find_center(Edges :: [[integer()]]) -> integer().
find_center(Edges) ->
  Map = find_center(Edges, #{}),
  EdgeSum = length(Edges),
  List = maps:to_list(Map),
  find_ans(List, EdgeSum).

find_center([], Map) ->
  Map;
find_center([Edge | Rest], Map) ->
  NewMap1 =
    maps:update_with(
      lists:nth(1, Edge), fun(X) -> X + 1 end, 1, Map),
  NewMap2 =
    maps:update_with(
      lists:nth(2, Edge), fun(X) -> X + 1 end, 1, NewMap1),
  find_center(Rest, NewMap2).

find_ans([H | T], EdgeSum) ->
  {K, V} = H,
  case V of
    EdgeSum ->
      K;
    _ ->
      find_ans(T, EdgeSum)
  end.
