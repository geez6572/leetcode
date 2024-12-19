-module(largest_altitude).

-spec largest_altitude(Gain :: [integer()]) -> integer().
largest_altitude(Gain) ->
  recur(0, Gain).

-spec recur(Pre :: integer(), Gain :: [integer()]) -> integer().
recur(_, []) ->
  0;
recur(Pre, [H | T]) ->
  Cur = H + Pre,
  Rest = recur(Cur, T),
  case Cur > Rest of
    true ->
      Cur;
    false ->
      Rest
  end.
