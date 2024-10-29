use std::io::{ Write, BufRead };

struct Stdin {
  stdin: std::io::BufReader<std::io::StdinLock<'static>>,
}

impl Stdin {
  fn new() -> Self {
    let stdin = std::io::stdin();
    let stdin = stdin.lock();
    let stdin = std::io::BufReader::new(stdin);
    
    Stdin { stdin }
  }

  fn read_line(&mut self) -> String {
    let mut input = String::new();
    self.stdin.read_line(&mut input).unwrap();

    input
  }
}

struct Stdout {
  stdout: std::io::BufWriter<std::io::StdoutLock<'static>>
}

impl Stdout {
  fn new() -> Self {
    let stdout = std::io::stdout();
    let stdout = stdout.lock();
    let stdout = std::io::BufWriter::new(stdout);

    Stdout { stdout }
  }

  fn writeln(&mut self, str: String) {
    writeln!(self.stdout, "{}", str).unwrap();
  }
}

fn main() {
    let mut stdin = Stdin::new();
    let mut stdout = Stdout::new();

    let n: usize = stdin.read_line().trim().parse::<usize>().unwrap();
    let mut seq:Vec<i32> = vec![];
    let mut index: Vec<usize> = vec![];
    let mut v: Vec<i32> = vec![];

    for num in stdin.read_line().trim().split_whitespace() {
      seq.push(num.parse::<i32>().unwrap());
      index.push(0);
    }

    for i in 0..n {
      if v.len() == 0 || v[v.len() - 1] < seq[i] {
        v.push(seq[i]);
        index[i] = v.len() - 1;
      } else {
        let mut l = 0;
        let mut r = v.len() - 1;
        while l < r {
          let m = (l + r) / 2;
          if v[m] >= seq[i] {
            r = m;
          } else {
            l = m + 1;
          }
        }
        v[l] = seq[i];
        index[i] = l;
      }
    }

    stdout.writeln(v.len().to_string());
    let mut ans: Vec<i32> = vec![];
    let mut f = v.len() - 1;

    for i in (0..n).rev() {
      if index[i] == f {
        if f != 0 {
          f -= 1;
        }
        ans.push(seq[i]);
        if ans.len() == v.len() {break;}
      }
    }

    let mut ans_str = String::new();

    for i in (0..ans.len()).rev() {
      ans_str.push_str(&ans[i].to_string());
      ans_str.push(' ');
    }

    stdout.writeln(ans_str);

}