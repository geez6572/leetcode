-module(valid_strings).

-spec valid_strings(N :: integer()) -> [unicode:unicode_binary()].
valid_strings(N) ->
  valid_strings(0, 1, N).

valid_strings(Cur, _, N) when Cur =:= N ->
  1;
valid_strings(Cur, Pre, N) ->
  case Pre of
    $0 ->
      valid_strings(Cur + 1, 1, N);
    _ ->
      valid_strings(Cur + 1, 0, N) + valid_strings(Cur, 1, N)
  end.
