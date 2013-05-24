import scala.util.Random

val names = List("おっくん", "きたけー", "たけお", "ぐっさん")
(new Random).shuffle(names).foreach { println }

// macの場合 export JAVA_OPTS='-Dfile.encoding=UTF-8' が必要
