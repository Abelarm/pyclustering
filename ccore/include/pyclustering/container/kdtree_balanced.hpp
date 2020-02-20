/*!

@authors Andrei Novikov (pyclustering@yandex.ru)
@date 2014-2020
@copyright GNU Public License

@cond GNU_PUBLIC_LICENSE
    pyclustering is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    pyclustering is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
@endcond

*/


#pragma once

#include "kdnode.hpp"

#include <functional>
#include <memory>
#include <vector>

#include <pyclustering/definitions.hpp>


namespace pyclustering {

namespace container {


/*!

@brief   Represents balanced static KD-tree that does not provide services to add and remove nodes after
          initialization.

@details In the term KD tree, k denotes the dimensionality of the space being represented. Each data point is
          represented as a node in the k-d tree in the form of a record of type node.

There is an example how to create KD-tree:
@code
    TODO:
@endcode

There is an illustration of balanced KD-tree above that has been done by python version of pyclustering library.
@image html kd_tree_balanced_lsun.png "Fig. 1. Balanced KD-tree for sample 'Lsun'."

Implementation based on paper @cite book::the_design_and_analysis.

*/
class kdtree_balanced {
protected:
    kdnode::ptr     m_root = nullptr;

    std::size_t     m_dimension = 0;

    std::size_t     m_size = 0;

public:
    /*!
    
    @brief Default constructor of balanced KD-tree.
    
    */
    kdtree_balanced() = default;

    /*!

    @brief Parameterized constructor of balanced KD-tree.

    @param[in] p_data: data that should be stored in the tree.
    @param[in] p_payloads: payload for each point in `p_data`.

    */
    kdtree_balanced(const dataset & p_data, const std::vector<void *> p_payloads = { });

    /*!

    @brief Default copy constructor of balanced KD-tree.

    @param[in] p_other: another tree that is used as a copy for constructed tree.

    */
    kdtree_balanced(const kdtree_balanced & p_other) = default;

    /*!

    @brief Default move constructor of balanced KD-tree.

    @param[in,out] p_other: another tree that is used to move to constructed tree.

    */
    kdtree_balanced(kdtree_balanced && p_other) = default;

    /*!

    @brief Default deconstructor of balanced KD-tree.

    */
    virtual ~kdtree_balanced() = default;

public:
    /*!
    
    @brief   Find node in KD-tree using coordinates.
    
    @param[in] p_point: coordinates of searched node.
    
    @return  Pointer to found node in tree.
    
    */
    kdnode::ptr find_node(const point & p_point) const;

    /*!
    
    @brief   Find node in KD-tree using coordinates.
    
    @param[in] p_point: coordinates of searched node.
    @param[in] p_payload: payload that is used to identify node.
    
    @return  Pointer to found node in tree.
    
    */
    kdnode::ptr find_node(const point & p_point, const void * p_payload) const;

    /*!
    
    @brief   Return the root of the tree.
    
    @return  Returns pointer to the root of the tree.
    
    */
    kdnode::ptr get_root() const;

    /*!
    
    @brief   Return size of KD-tree.
    
    @return  Returns amount of nodes in KD-tree.
    
    */
    std::size_t get_size() const;

protected:
    /*!

    @brief   Creates sub-tree of KD-tree from node `p_parent`.

    @param[in] p_begin: iterator to the beginning of the collection that should be used to build KD-tree.
    @param[in] p_end: iterator to the end of the collection that should be used to build KD-tree.
    @param[in] p_parent: node that is parent for tree that is going to be built.
    @param[in] p_depth: depth of the tree that where children of the `parent` should be placed.

    @return  Returns a node that is a root for the created sub-tree.

    */
    kdnode::ptr create_tree(
        std::vector<kdnode::ptr>::iterator p_begin, 
        std::vector<kdnode::ptr>::iterator p_end,
        const kdnode::ptr & p_parent, const std::size_t p_depth);

public:
    /*!

    @brief   Assignment operator for KD-tree.

    @param[in] p_other: another KD-tree that should be copied to the tree.

    @return  Returns reference to KD-tree to where another tree was copied.

    */
    kdtree_balanced & operator=(const kdtree_balanced & p_other);

    /*!

    @brief   Movement operator for KD-tree.

    @param[in,out] p_other: another KD-tree that should be moved to the tree.

    @return  Returns reference to KD-tree to where another was moved.

    */
    kdtree_balanced & operator=(kdtree_balanced && p_other);
};


}

}