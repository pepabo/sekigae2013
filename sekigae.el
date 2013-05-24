(random t)
(message "%s"
         (sort '("たけお" "きたけー" "ぐっさん" "おっくん")
               '(lambda (a b)
                  (eq 0 (random 2)))))
