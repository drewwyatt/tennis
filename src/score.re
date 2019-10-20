let _pointValue = ["0", "15", "30", "40", "Adv"];

type t =
  | Points(int, int)
  | Winner(Player.t);

let _did_win = (wScore, lScore) => wScore + 1 >= 4 && wScore > lScore;

let _increment = points =>
  switch (points) {
  | (4, 4) => Points(3, 3)
  | (a, b) => Points(a, b)
  };

let _to_points = List.nth(_pointValue);

let update = ((a, b), player) =>
  switch (player) {
  | Player.A => _did_win(a, b) ? Winner(Player.A) : _increment((a + 1, b))
  | Player.B => _did_win(b, a) ? Winner(Player.B) : _increment((a, b + 1))
  };

let format = score =>
  switch (score) {
  | Points(a, b) => a->_to_points ++ " - " ++ b->_to_points
  | Winner(p) => "Game " ++ p->Player.to_string
  };

let _tabulate = round => {
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

let of_round = round => _tabulate(round) |> Array.map(format);