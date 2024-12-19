-module(build_array).

-export([test/0]).

-spec build_array(Nums :: [integer()]) -> [integer()].
build_array(Nums) ->
  Tuples = list_to_tuple(Nums),
  build_array(Tuples, []).

build_array(Nums, Rs) when length(Rs) =:= tuple_size(Nums) ->
  Rs;
build_array(Nums, Rs) ->
  CurIndex = length(Rs) + 1,
  NextIndex = element(CurIndex, Nums),
  NewRs = Rs ++ [element(NextIndex, Nums)],
  build_array(Nums, NewRs).

test() ->
  Nums = [0, 2, 1, 5, 3, 4],
  build_array(Nums).
