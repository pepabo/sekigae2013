var freshers = ["おっくん", "ぐっさん", "たけお", "きたけー"];

freshers.shuffle = function () {
  var i = this.length;
  var j = 0;
  var tmp = "";
  while(i > 0) {
    j = Math.floor(Math.random()*i);
    i -= 1;
    tmp = this[i];
    this[i] = this[j];
    this[j] = tmp;
  }

  return this;
};

freshers.shuffle();
console.log(freshers.join(" | "));
