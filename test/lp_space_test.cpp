// Software License Agreement (BSD-3-Clause)
//
// Copyright 2018 The University of North Carolina at Chapel Hill
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
//
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above
//    copyright notice, this list of conditions and the following
//    disclaimer in the documentation and/or other materials provided
//    with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its
//    contributors may be used to endorse or promote products derived
//    from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
// INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
// OF THE POSSIBILITY OF SUCH DAMAGE.

//! @author Jeff Ichnowski

#include <nigh/lp_space.hpp>
#include "test.hpp"

TEST(distance_l2) {
    using namespace unc::robotics::nigh;
    using Space = metric::L2Space<double, 3>;

    EXPECT((std::is_same_v<typename Space::Type, Eigen::Vector3d>)) == true;

    Space space;
    EXPECT(space.distance(Eigen::Vector3d(1,2,3), Eigen::Vector3d(1,1,1)))
        == std::sqrt(0.0 + 1.0 + 2.0*2.0);
}

TEST(distance_l1) {
    using namespace unc::robotics::nigh;
    metric::L1Space<double, 3> space;
    EXPECT(space.distance(Eigen::Vector3d(1,2,3), Eigen::Vector3d(1,1,1)))
        == 0.0 + 1.0 + 2.0;
}

TEST(distance_linf) {
    using namespace unc::robotics::nigh;
    metric::LInfSpace<double, 3> space;
    EXPECT(space.distance(Eigen::Vector3d(1,2,3), Eigen::Vector3d(1,1,1)))
        == 2.0;
}
