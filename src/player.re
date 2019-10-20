type t =
  | A
  | B;
let of_char = c => c === 'A' ? A : B;
let to_string = p => p === A ? "A" : "B";