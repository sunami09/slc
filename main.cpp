// CSCI 311 - Spring 2023
// Lab 1 Skeleton
// Author: Carter Tillquist

#include <iostream>
#include <math.h>
#include <chrono>
#include <vector>

using namespace std;

/**************************
 * Your solutions go here *
 * ************************/
int collatzLength(int n){
  int result = 0; // Tracks the number of iterations
  while(n != 1){ // ends the sequence when reached 1
    if(n % 2 == 0){
      n /= 2;
    }else{
      n = (3 * n) + 1;
    }
    result++;
  }
  return result; 
}

void printStats(const vector<int> &v){
  if(!v.size()){ // For empty vector
    cout << "Empty vector\n";
    return;
  }
  int max = v[0]; // Track Max
  int min = v[0]; // Track Min
  int sum = 0;
  for(int i = 0; i < v.size(); i++){
    if(v[i] > max){ // Update Max
      max = v[i];
    }
    if(v[i] < min){ // Update Min
      min = v[i];
    }
    sum += v[i]; // Update Sum for mean
  }
  float mean = (float)sum / v.size();
  cout << min << " " << mean << " " << max << endl;
}

int sumMultiples(const vector<int> &v, int n){
  int result = 0;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < v.size(); j++){
      if(i % v[j] == 0){
        result += i; // Updates sum when any number is divisible by an element in the vector
        break;
      }
    }
  }

  return result;
}

void greaterThanK(vector<int> &v, int k){
  for(int i = 0; i < v.size(); i++){
    if(v[i] <= k){
      v.erase(v.begin() + i); // Pop element less than K
      i--;
    }
  } 
}

bool isSubarray(const vector<string> &a, const vector<string> &b){
  for(int i = 0; i < b.size(); i++){
    if(a[0] == b[i]){
      for(int j = 0; j < a.size(); j++){ // Match elements Sequentially
        if(j + i == b.size()){
          return false;
        }
        if(a[j] != b[j + i]){
          break;
        }
        if(j == a.size() - 1){
          return true;
        }
      }
    }
  }
  return false;
}

bool isPrimeA(int n){
  for(int i = 2; i < n; i++){ // O(n) Time 
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int sumPrimesA(int n){
  int result = 0;
  for(int i = 2; i < n; i++){ // O(n^2)
    if(isPrimeA(i)){
      result += i;
    }
  }
  return result;
}

bool isPrimeB(int n){
  for(int i = 2; i * i <= n; i++){ // O(sqrt(n))
    if(n % i == 0){
      return false;
    }
  }
  return true;
}

int sumPrimesB(int n){
  int result = 0;
  for(int i = 2; i < n; i++){// O(n sqrt(n))
    if(isPrimeB(i)){
      result += i;
    }
  }
  return result;
}

int sieveOfEratosthenes(int n){
  vector<int> primes(n + 1, 1);
  for(int i = 2; i<= n; i++){ // O(n log(log(n)))
    if(primes[i]){
      for(int j = 2; j * i <= n; j++){
        primes[i * j] = 0; // Deleting non-primes
      }
    }
  }
  

  int result = 0;
  for(int i = 2; i < n; i++){
    if(primes[i] == 1){
      result += i; // Adding to result;
    }
  }

  return result;
}

/***********************************************
 * Main and helper functions for quick testing *
 * *********************************************/
void readIntVector(vector<int> &v, int n);
void timePrimes();

int main(){
  int question = -1;
  cout << "Question: ";
  cin >> question;

  int n = 0, k = 0, m = 0;
  vector<int> v;
  string s = "";
  vector<string> a;
  vector<string> b;

  switch (question){
    case 1: //collatzLength
      cout << "Collatz Sequence n: ";
      cin >> n;
      cout << collatzLength(n) << endl;
      break;
    case 2: //printStats
      cout << "Print Stats Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Stats: " << endl;
      printStats(v);
      break;
    case 3: //sumMultiples
      cout << "Sum Multiples Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "Max Value: ";
      cin >> k;
      cout << "Sum: ";
      cout << sumMultiples(v, k) << endl;
      break;
    case 4: //greaterThanK
      cout << "Greater than K Number of Values: ";
      cin >> n;
      cout << "Values: ";
      readIntVector(v, n);
      cout << "k: ";
      cin >> k;
      cout << "Result: ";
      greaterThanK(v, k);
      for (int j = 0; j < v.size(); j++){ cout << v[j] << " "; }
      break;
    case 5: //isSubarray
      cout << "Is Subarray Array Sizes: ";
      cin >> n >> m;
      cout << "Values for First Vector: ";
      for (int i = 0; i < n; i++){
        cin >> s;
        a.push_back(s);
      }
      cout << "Values for Second Vector: ";
      for (int i = 0; i < m; i++){
        cin >> s;
        b.push_back(s);
      }
      cout << "Result: ";
      cout << isSubarray(a, b) << endl;
      break;
    case 6: //naive prime sum
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sumPrimesA(n) << endl;
      break;
    case 7: //prime sum 2
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sumPrimesB(n) << endl;
      break;
    case 8: //sieve of eratosthenes
      cout << "Primes Max Value: ";
      cin >> n;
      cout << "Sum: " << sieveOfEratosthenes(n) << endl;
      break;
    case 9: //time primes
      cout << "Time Primes" << endl;
      timePrimes();
      break;
  }

  return 0;
}

/**************************************************
 * Read a vector of integers in from cin          *
 * v - vector<int> & - the integer vector to fill *
 * n - int - the number of integers to read       *
 * ************************************************/
void readIntVector(vector<int> &v, int n){
  int m = 0;
  for (int i = 0; i < n; i++){
    cin >> m;
    v.push_back(m);
  }
}

/***************************************************************************************************
 * Testing run times of different approaches to finding the sum of prime numbers under a threshold *
 * *************************************************************************************************/
void timePrimes(){
  int sum = -1;
  chrono::high_resolution_clock::time_point start;
  chrono::high_resolution_clock::time_point end;
  double elapsed = -1;
  vector<int> x = {10, 100, 1000, 10000, 100000, 500000};
  for (int i = 0; i < x.size(); i++)
  {
    cout << "Value: " << x[i] << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesA(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "A ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sumPrimesB(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "B ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;

    start = chrono::high_resolution_clock::now();
    sum = sieveOfEratosthenes(x[i]);
    end = chrono::high_resolution_clock::now();
    elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
    cout << "C ... Sum: " << sum << ", Time elapsed: " << elapsed << endl;
    cout << endl << endl;
  }

  cout << "Sieve of Eratosthenes on primes below 1 million" << endl;
  start = chrono::high_resolution_clock::now();
  long sum2 = sieveOfEratosthenes(1000000);
  end = chrono::high_resolution_clock::now();
  elapsed = chrono::duration_cast<chrono::duration<double>>(end - start).count();
  cout << "Sum: " << sum2 << ", Time elapsed: " << elapsed << endl;
  cout << endl << endl;
}

