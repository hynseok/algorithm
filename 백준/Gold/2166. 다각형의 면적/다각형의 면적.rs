use std::io::stdin;

fn main() {
    let mut buffer = String::new();
    stdin().read_line(&mut buffer).unwrap();
  
    let n = buffer.trim().parse::<usize>().unwrap();
    
    let mut x_coor: Vec<f64> = vec![];
    let mut y_coor: Vec<f64> = vec![];

    for _ in 0..n {
      buffer.clear();
      stdin().read_line(&mut buffer).unwrap();
      let vec: Vec<f64> = buffer
        .trim()
        .split(" ")
        .map(|x| x.parse::<f64>()).into_iter()
        .filter_map(Result::ok)
        .collect();
      
      x_coor.push(vec[0]);
      y_coor.push(vec[1]);
    }

    let mut ans: f64 = 0.0;
    for i in 2..n {
        ans += x_coor[0] * y_coor[i-1] + x_coor[i-1] * y_coor[i] + x_coor[i] * y_coor[0];
        ans -= x_coor[i-1] * y_coor[0] + x_coor[i] * y_coor[i-1] + x_coor[0] * y_coor[i];
    }
    ans /= 2.0;
    let precision = 1;
    println!("{:.1$}",ans.abs(),precision);
  }