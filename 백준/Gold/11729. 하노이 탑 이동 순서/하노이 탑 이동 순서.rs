use std::io::{self, Write, BufRead};

struct Stdin {
    stdin: io::BufReader<io::StdinLock<'static>>,
}

impl Stdin {
    fn new() -> Self {
        let stdin = io::stdin();
        let stdin = stdin.lock();
        let stdin = io::BufReader::new(stdin);
        
        Stdin { stdin }
    }

    fn read_line(&mut self) -> String {
        let mut input = String::new();
        self.stdin.read_line(&mut input).unwrap();
        input
    }
}

struct Stdout {
    stdout: io::BufWriter<io::StdoutLock<'static>>,
}

impl Stdout {
    fn new() -> Self {
        let stdout = io::stdout();
        let stdout = stdout.lock();
        let stdout = io::BufWriter::new(stdout);

        Stdout { stdout }
    }

    fn write_line(&mut self, s: &str) {
        writeln!(self.stdout, "{}", s).unwrap();
    }
}

fn hanoi(n: i32, start: i32, to: i32, bypass: i32, stdout: &mut Stdout) {
    if n == 1 {
        stdout.write_line(&format!("{} {}", start, to));
    } else {
        hanoi(n - 1, start, bypass, to, stdout);
        
        stdout.write_line(&format!("{} {}", start, to));
        
        hanoi(n - 1, bypass, to, start, stdout);
    }
}

fn main() {
    let mut stdin = Stdin::new();
    let mut stdout = Stdout::new();

    let line = stdin.read_line();
    let num: u32 = line.trim().parse().expect("유효한 숫자를 입력하세요.");

    stdout.write_line(&((1_u64 << num) - 1).to_string());

    if num > 0 {
        hanoi(num as i32, 1, 3, 2, &mut stdout);
    }
    
}
