-module(count_asterisks).

-spec count_asterisks(S :: unicode:unicode_binary()) -> integer().
count_asterisks(S) ->
  List = binary_to_list(S),
  recur(List, false, 0).

recur([], _, PreCount) ->
  PreCount;
recur([H | T], HasPre, PreCount) ->
  case H of
    $* ->
      recur(T, HasPre, PreCount + 1);
    $| ->
      if HasPre ->
           recur(T, false, 0);
         true ->
           PreCount + recur(T, false, 0)
      end;
    _ ->
      recur(T, HasPre, PreCount)
  end.
