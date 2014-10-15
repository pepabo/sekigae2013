(* Random.int returns [0, 3) *)
(* ((Random.int 3) - 1) returns -1 or 0 or 1. *)
(* $ ocamlc -o sekigae sekigae.ml *)
(* $ ./sekigae *)

Random.self_init()
let shuffle = Array.sort (fun _ _ -> (Random.int 3) - 1)
let ary = [|"okkun"; "kitak"; "keoken"; "gussan"|]
let _ = shuffle ary
let () = Array.iter (Printf.printf "%s ") ary
