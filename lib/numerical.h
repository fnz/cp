#pragma once

#pragma mark - Factorization

template<typename number_type>
std::vector<number_type> sieve(const number_type& n) {
	std::vector<bool> is_prime(n+1, true);
	is_prime[0] = is_prime[1] = false;
	for (int i = 2; i <= n/2; i++) {
		if (!is_prime[i]) continue;
		if (i*1LL*i <= n) {
			for (int j = 2*i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	std::vector<number_type> primes;
	for (int i = 2; i <= n/2; i++) {
		if (!is_prime[i]) continue;
		primes.push_back(i);
	}
	return primes;
}

template<typename number_type>
std::vector<number_type> factorize(const number_type& n, const std::vector<number_type>& primes) {
	number_type i = 0;
	number_type limit = primes.size();
	number_type zero_powers_count = 0;
	std::vector<number_type> prime_powers;
	while (n >= primes[i] && i < limit) {
		number_type power = 0;
		number_type divisor = primes[i];
		while (n%divisor == 0) {
			divisor *= primes[i];
			power++;
		}
		if (power) {
			if (zero_powers_count) {
				for (number_type j = 0; j < zero_powers_count; j++) {
					prime_powers.push_back(0);
				}
				zero_powers_count = 0;
			}
			prime_powers.push_back(power);
		} else {
			zero_powers_count++;
		}
		i++;
	}
	return prime_powers;
}

#pragma mark - GCD and LCM

template <typename number_type>
number_type gcd (number_type a, number_type b) {
	while (b) {
		a %= b;
		std::swap(a, b);
	}
	return a;
}

template <typename number_type>
number_type lcm (number_type a, number_type b) {
	return (a/gcd (a, b))*b;
}

template<typename number_type>
std::vector<number_type> lcm(const std::vector<number_type>& x, const std::vector<number_type>& y) {
	std::vector<number_type> ret;
	number_type xsz = x.size();
	number_type ysz = y.size();
	for (number_type i = 0; i < max(xsz, ysz); i++) {
		if (i < xsz && i < ysz) {
			ret.push_back(max(x[i], y[i]));
		} else if (i >= ysz) {
			ret.push_back(x[i]);
		} else {
			ret.push_back(y[i]);
		}
	}
	return ret;
}

template<typename number_type>
std::vector<number_type> gcd(const std::vector<number_type>& x, const std::vector<number_type>& y) {
	std::vector<number_type> ret;
	for (number_type i = 0; i < min(x.size(), y.size()); i++) {
		ret.push_back(min(x[i], y[i]));
	}
	return ret;
}

#pragma mark - Fast power

template <typename number_type>
number_type bin_pow (number_type a, number_type n) {
	number_type res = 1;
	while (n) {
		if (n & 1) {
            res *= a;
        }
		a *= a;
		n >>= 1;
	}
	return res;
}

#pragma mark - Mod

template <typename number_type>
number_type mod_pow (number_type a, number_type n, number_type m) {
	number_type res = 1;
	while (n) {
		if (n & 1) {
            res *= a;
            res %= m;
        }
		a *= a;
        a %= m;
		n >>= 1;
	}
	return res;
}

template <typename number_type>
number_type inv_mod (number_type a, number_type m) {
    return mod_pow(a, m-2, m);
}

double factorial(int x) {
	double ans = 1.0;
	while(x > 0) {
		ans *= (double)x;
		x--;
	}
	return ans;
}

double choose(int n, int k) {
    if (k > n) {
        return 0;
    }
    int r = 1;
    for (int d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return 1.0*r;
}
