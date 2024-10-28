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

fn binomial(n: usize, k: usize) -> usize {
  if k == 1 {
    return n;
  }
  if k == 0 || n == k {
    return 1;
  }
  if n - k == 1 {
    return n;
  }
     
  let mut a: usize = 1;
  let mut b: usize = 1;
  let mut ans: usize = 1;

    for i in (n - k + 1..=n).rev() {
      a = (a * i) % 1000000007;
    }
  
    for i in 1..=k {
      b = (b * i) % 1000000007;
    }
  
    ans = (a * mod_inverse(b, 1000000007)) % 1000000007;
    ans
}
  
fn mod_inverse(a: usize, m: usize) -> usize {
  mod_exp(a, m - 2, m)
}
  
fn mod_exp(mut base: usize, mut exp: usize, modulus: usize) -> usize {
  let mut result = 1;
  while exp > 0 {
    if exp % 2 == 1 {
      result = (result * base) % modulus;
    }
    base = (base * base) % modulus;
    exp /= 2;
  }
  result
}

fn main() {
    let mut stdin = Stdin::new();
    let mut stdout = Stdout::new();

    let line = stdin.read_line();

    let args: Vec<&str> = line.trim().split_whitespace().collect();

    let n:usize = args[0].parse::<usize>().unwrap();
    let k:usize = args[1].parse::<usize>().unwrap();

    let ans = binomial(n, k);

    stdout.writeln(ans.to_string());
}