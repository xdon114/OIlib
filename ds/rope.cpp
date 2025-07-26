#include <bits/stdc++.h>
#define fil [[gnu::always_inline]] inline
using namespace std; typedef long long ll;

struct Rope {
    constexpr static ll B = 300, MAXB = B * 2, MINB = B / 2;
    typedef list<vector<ll>>::iterator Gp; typedef vector<ll>::iterator Ip;
    mutable list<vector<ll>> a; mutable ll n;
    struct Pt { mutable Gp g; mutable Ip i; };
    fil void insert(ll i, ll x, Gp g = {}, Pt p = {}) const {
        (g = (p = _find(i)).g)->insert(p.i, x);
        if (g->size() >= MAXB) {
            a.emplace(++Gp(g), g->begin() + g->size() / 2, g->end());
            g->resize(g->size() / 2);
        }
    } fil void erase(ll i, Gp g = {}, Pt p = {}) const {
        (g = (p = _find(i)).g)->erase(p.i);
        if (g->size() < MINB && (g == a.begin() || _join(--Gp(g)))) _join(g);
    } fil Pt _find(ll i) const { // O(sqrt n)
        for (Gp g = a.begin(); g != a.end(); ++g) {
            if (i < g->size()) return Pt {g, g->begin() + i};
            i -= g->size();
        } return Pt {--a.end(), (--a.end())->end()};
    } fil bool _join(Gp g, Gp f = {}) const { // 1 for bad
        return  (f = g++, g == a.end()) ? 1 :
                (f->insert(f->end(), g->begin(), g->end()), a.erase(g), 0);
    }
};
