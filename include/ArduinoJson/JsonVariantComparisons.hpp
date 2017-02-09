// Copyright Benoit Blanchon 2014-2017
// MIT License
//
// Arduino JSON library
// https://github.com/bblanchon/ArduinoJson
// If you like this project, please add a star!

#pragma once

#include "JsonVariantBase.hpp"
#include "StringTraits/StringTraits.hpp"
#include "TypeTraits/EnableIf.hpp"

namespace ArduinoJson {
template <typename TImpl, typename TComparand>
inline typename TypeTraits::EnableIf<!TypeTraits::IsVariant<TComparand>::value,
                                     bool>::type
operator==(TComparand comparand, const JsonVariantBase<TImpl> &variant) {
  return variant.operator==(comparand);
}

template <typename TImpl, typename TComparand>
inline bool operator!=(TComparand comparand,
                       const JsonVariantBase<TImpl> &variant) {
  return !variant.operator==(comparand);
}

template <typename TImpl, typename TComparand>
inline bool operator<=(const JsonVariantBase<TImpl> &left, TComparand right) {
  return left.template as<TComparand>() <= right;
}

template <typename TImpl, typename TComparand>
inline bool operator<=(TComparand comparand,
                       const JsonVariantBase<TImpl> &variant) {
  return comparand <= variant.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator>=(const JsonVariantBase<TImpl> &variant,
                       TComparand comparand) {
  return variant.template as<TComparand>() >= comparand;
}

template <typename TImpl, typename TComparand>
inline bool operator>=(TComparand comparand,
                       const JsonVariantBase<TImpl> &variant) {
  return comparand >= variant.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator<(const JsonVariantBase<TImpl> &varian,
                      TComparand comparand) {
  return varian.template as<TComparand>() < comparand;
}

template <typename TImpl, typename TComparand>
inline bool operator<(TComparand comparand,
                      const JsonVariantBase<TImpl> &variant) {
  return comparand < variant.template as<TComparand>();
}

template <typename TImpl, typename TComparand>
inline bool operator>(const JsonVariantBase<TImpl> &variant,
                      TComparand comparand) {
  return variant.template as<TComparand>() > comparand;
}

template <typename TImpl, typename TComparand>
inline bool operator>(TComparand comparand,
                      const JsonVariantBase<TImpl> &variant) {
  return comparand > variant.template as<TComparand>();
}
}
