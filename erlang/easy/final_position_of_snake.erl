-module(final_position_of_snake).

-spec final_position_of_snake(N :: integer(), Commands :: [unicode:unicode_binary()]) ->
                               integer().
final_position_of_snake(N, Commands) ->
  CurPos = [0, 0],
  final_position_of_snake(N, Commands, CurPos).

final_position_of_snake(N, [_], CurPos) ->
  N * lists:nth(1, CurPos) + lists:nth(2, CurPos);
final_position_of_snake(N, [H | T], CurPos) ->
  case H of
    "UP" ->
      NextPos = [lists:nth(1, CurPos) - 1, lists:nth(2, CurPos)],
      final_position_of_snake(N, T, NextPos);
    "DOWN" ->
      NextPos = [lists:nth(1, CurPos) + 1, lists:nth(2, CurPos)],
      final_position_of_snake(N, T, NextPos);
    "LEFT" ->
      NextPos = [lists:nth(1, CurPos), lists:nth(2, CurPos) - 1],
      final_position_of_snake(N, T, NextPos);
    _ ->
      NextPos = [lists:nth(1, CurPos), lists:nth(2, CurPos) + 1],
      final_position_of_snake(N, T, NextPos)
  end.
