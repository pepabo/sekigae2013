:random.seed :os.timestamp

["おっくん", "ぐっさん", "たけお", "きたけー"]
|> Enum.shuffle
|> Enum.join(" | ")
|> IO.puts
