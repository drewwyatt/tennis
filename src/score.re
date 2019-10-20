type t =
  | Points(int, int)
  | Winner(Player.t);

let didWin = (wScore, lScore) => wScore + 1 >= 4 && wScore > lScore;

let update = ((a, b), player) =>
  switch (player) {
  | Player.A => didWin(a, b) ? Winner(Player.A) : Points(a + 1, b)
  | Player.B => didWin(b, a) ? Winner(Player.B) : Points(a, b + 1)
  };

let print = ((a, b)) => a->string_of_int ++ " - " ++ b->string_of_int;

let of_round = round => {
  let acc = ref(Points(0, 0));
  Array.map(
    winner => {
      let prev = acc^;
      acc :=
        (
          switch (prev) {
          | Points(a, b) => update((a, b), winner)
          | _ => prev
          }
        );
      acc^;
    },
    round,
  );
};