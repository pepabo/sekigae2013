(use srfi-27)

(random-source-randomize! default-random-source)
(define freshers (list "okkun" "gussan" "keoken" "kitak"))

(print
  (string-join
    (map  
      (lambda (x) 
        (car (cdr x)))
      (sort (map (lambda (x)
              (list (random-real) x)) freshers)
              (lambda (x y) (< (car x) (car y))))) " | "))
