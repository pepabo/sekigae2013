-module(sekigae).
-export([main/0]).

main() ->
    L = [okkun, kitak, keoken, gussan],
    lists:foreach(fun(N) -> io:format("~p~n", [N]) end, shuffle(L)).

shuffle(List) ->
    random:seed(os:timestamp()),
    L = [{random:uniform(), X} || X <- List],
    [X || {_,X} <- lists:sort(L)].
