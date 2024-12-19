-module(can_make_arithmetic_progression).

-export([quickSort/1]).

-spec can_make_arithmetic_progression(Arr :: [integer()]) -> boolean().
quickSort([]) ->
  [];
quickSort([H]) ->
  [H];
quickSort([H | T]) ->
  quickSort(lists:filter(fun(X) -> X < H end, T))
  ++ [H]
  ++ quickSort(lists:filter(fun(X) -> X > H end, T)).

can_make_arithmetic_progression(Arr) ->
  NewArr = quickSort(Arr),
  is_seq(NewArr).

-spec is_seq(List :: [integer()]) -> boolean().
is_seq([]) ->
  true;
is_seq([_]) ->
  true;
is_seq([A, B | Rest]) ->
  Diff = B - A,
  is_seq([B | Rest], Diff).

-spec is_seq(List :: [integer()], Diff :: integer()) -> boolean().
is_seq([], _) ->
  true;
is_seq([_], _) ->
  true;
is_seq([A, B | Rest], Diff) when B - A =:= Diff ->
  is_seq([B | Rest], Diff);
is_seq(_, _) ->
  false.
