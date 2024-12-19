-module(time_required_to_buy).

-spec time_required_to_buy(Tickets :: [integer()], K :: integer()) -> integer().
time_required_to_buy(Tickets, K) ->
  Target = lists:nth(K + 1, Tickets),
  time_required_to_buy(Tickets, Target, K, 0, 0).

time_required_to_buy([], _, _, _, Rs) ->
  Rs;
time_required_to_buy([H | T], Target, K, Cur, Rs) ->
  case Cur =< K of
    true ->
      NewRs = Rs + min(H, Target),
      time_required_to_buy(T, Target, K, Cur + 1, NewRs);
    _ ->
      NewRs = Rs + min(H, Target - 1),
      time_required_to_buy(T, Target, K, Cur + 1, NewRs)
  end.
