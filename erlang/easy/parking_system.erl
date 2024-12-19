-module(parking_system).

-spec parking_system_init_(Big :: integer(), Medium :: integer(), Small :: integer()) ->
                            any().
parking_system_init_(Big, Medium, Small) ->
  case ets:info(park) of
    undefined ->
      ok;
    _Info ->
      ets:delete(park)
  end,
  ets:new(park, [named_table, public, set]),
  ets:insert(park, [{1, Big}, {2, Medium}, {3, Small}]).

-spec parking_system_add_car(CarType :: integer()) -> boolean().
parking_system_add_car(CarType) ->
  case ets:lookup(park, CarType) of
    [{Ctype, Count}] when Count > 0 ->
      ets:update_element(park, Ctype, {2, Count - 1}),
      true;
    _ ->
      false
  end.
