// -----------------------------------------------------------------------------
// This file was autogenerated by symforce from template:
//     function/FUNCTION.h.jinja
// Do NOT modify by hand.
// -----------------------------------------------------------------------------

#pragma once

#include <matrix/math.hpp>

namespace sym {

/**
 * This function was autogenerated from a symbolic function. Do not modify by hand.
 *
 * Symbolic function: compute_flow_xy_innov_var_and_hx
 *
 * Args:
 *     state: Matrix25_1
 *     P: Matrix24_24
 *     R: Scalar
 *     epsilon: Scalar
 *
 * Outputs:
 *     innov_var: Matrix21
 *     H: Matrix24_1
 */
template <typename Scalar>
void ComputeFlowXyInnovVarAndHx(const matrix::Matrix<Scalar, 25, 1>& state,
                                const matrix::Matrix<Scalar, 24, 24>& P, const Scalar R,
                                const Scalar epsilon,
                                matrix::Matrix<Scalar, 2, 1>* const innov_var = nullptr,
                                matrix::Matrix<Scalar, 24, 1>* const H = nullptr) {
  // Total ops: 401

  // Input arrays

  // Intermediate terms (51)
  const Scalar _tmp0 = 2 * state(3, 0);
  const Scalar _tmp1 = 2 * state(1, 0);
  const Scalar _tmp2 = _tmp1 * state(6, 0);
  const Scalar _tmp3 = -_tmp0 * state(4, 0) + _tmp2;
  const Scalar _tmp4 = state(24, 0) - state(9, 0);
  const Scalar _tmp5 =
      _tmp4 + epsilon * (2 * math::min<Scalar>(0, (((_tmp4) > 0) - ((_tmp4) < 0))) + 1);
  const Scalar _tmp6 = Scalar(1.0) / (_tmp5);
  const Scalar _tmp7 = (Scalar(1) / Scalar(2)) * _tmp6;
  const Scalar _tmp8 = _tmp7 * state(2, 0);
  const Scalar _tmp9 = _tmp0 * state(6, 0);
  const Scalar _tmp10 = _tmp1 * state(4, 0) + _tmp9;
  const Scalar _tmp11 = _tmp7 * state(0, 0);
  const Scalar _tmp12 = 2 * state(2, 0);
  const Scalar _tmp13 = 4 * state(5, 0);
  const Scalar _tmp14 = 2 * state(0, 0);
  const Scalar _tmp15 = _tmp14 * state(6, 0);
  const Scalar _tmp16 = _tmp12 * state(4, 0) - _tmp13 * state(1, 0) + _tmp15;
  const Scalar _tmp17 = _tmp7 * state(3, 0);
  const Scalar _tmp18 = _tmp12 * state(6, 0);
  const Scalar _tmp19 = -_tmp13 * state(3, 0) - _tmp14 * state(4, 0) + _tmp18;
  const Scalar _tmp20 = _tmp7 * state(1, 0);
  const Scalar _tmp21 = _tmp10 * _tmp11 + _tmp16 * _tmp17 - _tmp19 * _tmp20 - _tmp3 * _tmp8;
  const Scalar _tmp22 = _tmp10 * _tmp7;
  const Scalar _tmp23 = _tmp11 * _tmp16 + _tmp19 * _tmp8 - _tmp20 * _tmp3 - _tmp22 * state(3, 0);
  const Scalar _tmp24 = _tmp11 * _tmp19 - _tmp16 * _tmp8 - _tmp17 * _tmp3 + _tmp22 * state(1, 0);
  const Scalar _tmp25 = 1 - 2 * std::pow(state(3, 0), Scalar(2));
  const Scalar _tmp26 = _tmp25 - 2 * std::pow(state(1, 0), Scalar(2));
  const Scalar _tmp27 = _tmp26 * _tmp6;
  const Scalar _tmp28 = std::pow(_tmp5, Scalar(-2));
  const Scalar _tmp29 = _tmp0 * state(0, 0);
  const Scalar _tmp30 = _tmp1 * state(2, 0);
  const Scalar _tmp31 = -_tmp29 + _tmp30;
  const Scalar _tmp32 = _tmp0 * state(2, 0) + _tmp14 * state(1, 0);
  const Scalar _tmp33 =
      _tmp28 * (_tmp26 * state(5, 0) + _tmp31 * state(4, 0) + _tmp32 * state(6, 0));
  const Scalar _tmp34 = _tmp32 * _tmp6;
  const Scalar _tmp35 = _tmp31 * _tmp6;
  const Scalar _tmp36 = 4 * state(4, 0);
  const Scalar _tmp37 = _tmp1 * state(5, 0) - _tmp15 - _tmp36 * state(2, 0);
  const Scalar _tmp38 = _tmp14 * state(5, 0) + _tmp2 - _tmp36 * state(3, 0);
  const Scalar _tmp39 = _tmp0 * state(5, 0) - _tmp18;
  const Scalar _tmp40 = _tmp12 * state(5, 0) + _tmp9;
  const Scalar _tmp41 = -_tmp11 * _tmp40 + _tmp17 * _tmp37 + _tmp20 * _tmp39 - _tmp38 * _tmp8;
  const Scalar _tmp42 = _tmp0 * state(1, 0) - _tmp14 * state(2, 0);
  const Scalar _tmp43 = _tmp29 + _tmp30;
  const Scalar _tmp44 = _tmp25 - 2 * std::pow(state(2, 0), Scalar(2));
  const Scalar _tmp45 =
      _tmp28 * (_tmp42 * state(6, 0) + _tmp43 * state(5, 0) + _tmp44 * state(4, 0));
  const Scalar _tmp46 = _tmp44 * _tmp6;
  const Scalar _tmp47 = -_tmp11 * _tmp37 - _tmp17 * _tmp40 + _tmp20 * _tmp38 + _tmp39 * _tmp8;
  const Scalar _tmp48 = -_tmp11 * _tmp38 + _tmp17 * _tmp39 - _tmp20 * _tmp37 + _tmp40 * _tmp8;
  const Scalar _tmp49 = _tmp43 * _tmp6;
  const Scalar _tmp50 = _tmp42 * _tmp6;

  // Output terms (2)
  if (innov_var != nullptr) {
    matrix::Matrix<Scalar, 2, 1>& _innov_var = (*innov_var);

    _innov_var(0, 0) =
        R +
        _tmp21 * (P(0, 1) * _tmp23 + P(1, 1) * _tmp21 + P(2, 1) * _tmp24 - P(23, 1) * _tmp33 +
                  P(3, 1) * _tmp35 + P(4, 1) * _tmp27 + P(5, 1) * _tmp34 + P(8, 1) * _tmp33) +
        _tmp23 * (P(0, 0) * _tmp23 + P(1, 0) * _tmp21 + P(2, 0) * _tmp24 - P(23, 0) * _tmp33 +
                  P(3, 0) * _tmp35 + P(4, 0) * _tmp27 + P(5, 0) * _tmp34 + P(8, 0) * _tmp33) +
        _tmp24 * (P(0, 2) * _tmp23 + P(1, 2) * _tmp21 + P(2, 2) * _tmp24 - P(23, 2) * _tmp33 +
                  P(3, 2) * _tmp35 + P(4, 2) * _tmp27 + P(5, 2) * _tmp34 + P(8, 2) * _tmp33) +
        _tmp27 * (P(0, 4) * _tmp23 + P(1, 4) * _tmp21 + P(2, 4) * _tmp24 - P(23, 4) * _tmp33 +
                  P(3, 4) * _tmp35 + P(4, 4) * _tmp27 + P(5, 4) * _tmp34 + P(8, 4) * _tmp33) -
        _tmp33 * (P(0, 23) * _tmp23 + P(1, 23) * _tmp21 + P(2, 23) * _tmp24 - P(23, 23) * _tmp33 +
                  P(3, 23) * _tmp35 + P(4, 23) * _tmp27 + P(5, 23) * _tmp34 + P(8, 23) * _tmp33) +
        _tmp33 * (P(0, 8) * _tmp23 + P(1, 8) * _tmp21 + P(2, 8) * _tmp24 - P(23, 8) * _tmp33 +
                  P(3, 8) * _tmp35 + P(4, 8) * _tmp27 + P(5, 8) * _tmp34 + P(8, 8) * _tmp33) +
        _tmp34 * (P(0, 5) * _tmp23 + P(1, 5) * _tmp21 + P(2, 5) * _tmp24 - P(23, 5) * _tmp33 +
                  P(3, 5) * _tmp35 + P(4, 5) * _tmp27 + P(5, 5) * _tmp34 + P(8, 5) * _tmp33) +
        _tmp35 * (P(0, 3) * _tmp23 + P(1, 3) * _tmp21 + P(2, 3) * _tmp24 - P(23, 3) * _tmp33 +
                  P(3, 3) * _tmp35 + P(4, 3) * _tmp27 + P(5, 3) * _tmp34 + P(8, 3) * _tmp33);
    _innov_var(1, 0) =
        R +
        _tmp41 * (P(0, 0) * _tmp41 + P(1, 0) * _tmp47 + P(2, 0) * _tmp48 + P(23, 0) * _tmp45 -
                  P(3, 0) * _tmp46 - P(4, 0) * _tmp49 - P(5, 0) * _tmp50 - P(8, 0) * _tmp45) +
        _tmp45 * (P(0, 23) * _tmp41 + P(1, 23) * _tmp47 + P(2, 23) * _tmp48 + P(23, 23) * _tmp45 -
                  P(3, 23) * _tmp46 - P(4, 23) * _tmp49 - P(5, 23) * _tmp50 - P(8, 23) * _tmp45) -
        _tmp45 * (P(0, 8) * _tmp41 + P(1, 8) * _tmp47 + P(2, 8) * _tmp48 + P(23, 8) * _tmp45 -
                  P(3, 8) * _tmp46 - P(4, 8) * _tmp49 - P(5, 8) * _tmp50 - P(8, 8) * _tmp45) -
        _tmp46 * (P(0, 3) * _tmp41 + P(1, 3) * _tmp47 + P(2, 3) * _tmp48 + P(23, 3) * _tmp45 -
                  P(3, 3) * _tmp46 - P(4, 3) * _tmp49 - P(5, 3) * _tmp50 - P(8, 3) * _tmp45) +
        _tmp47 * (P(0, 1) * _tmp41 + P(1, 1) * _tmp47 + P(2, 1) * _tmp48 + P(23, 1) * _tmp45 -
                  P(3, 1) * _tmp46 - P(4, 1) * _tmp49 - P(5, 1) * _tmp50 - P(8, 1) * _tmp45) +
        _tmp48 * (P(0, 2) * _tmp41 + P(1, 2) * _tmp47 + P(2, 2) * _tmp48 + P(23, 2) * _tmp45 -
                  P(3, 2) * _tmp46 - P(4, 2) * _tmp49 - P(5, 2) * _tmp50 - P(8, 2) * _tmp45) -
        _tmp49 * (P(0, 4) * _tmp41 + P(1, 4) * _tmp47 + P(2, 4) * _tmp48 + P(23, 4) * _tmp45 -
                  P(3, 4) * _tmp46 - P(4, 4) * _tmp49 - P(5, 4) * _tmp50 - P(8, 4) * _tmp45) -
        _tmp50 * (P(0, 5) * _tmp41 + P(1, 5) * _tmp47 + P(2, 5) * _tmp48 + P(23, 5) * _tmp45 -
                  P(3, 5) * _tmp46 - P(4, 5) * _tmp49 - P(5, 5) * _tmp50 - P(8, 5) * _tmp45);
  }

  if (H != nullptr) {
    matrix::Matrix<Scalar, 24, 1>& _h = (*H);

    _h.setZero();

    _h(0, 0) = _tmp23;
    _h(1, 0) = _tmp21;
    _h(2, 0) = _tmp24;
    _h(3, 0) = _tmp35;
    _h(4, 0) = _tmp27;
    _h(5, 0) = _tmp34;
    _h(8, 0) = _tmp33;
    _h(23, 0) = -_tmp33;
  }
}  // NOLINT(readability/fn_size)

// NOLINTNEXTLINE(readability/fn_size)
}  // namespace sym
