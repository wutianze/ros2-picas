// Copyright 2016 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP__NODE_INTERFACES__NODE_BASE_INTERFACE_HPP_
#define RCLCPP__NODE_INTERFACES__NODE_BASE_INTERFACE_HPP_

#include <memory>
#include <mutex>
#include <string>
#include <vector>

#include "rcl/node.h"

#include "rclcpp/callback_group.hpp"
#include "rclcpp/context.hpp"
#include "rclcpp/guard_condition.hpp"
#include "rclcpp/macros.hpp"
#include "rclcpp/visibility_control.hpp"

namespace rclcpp
{

#ifdef INTERNEURON

enum class MonitorTime{
  ReferenceTime,
  RemainTime,
  WaitTime
}
/*
* Struct for recording history of one time point
*/
class TimePoint{
public:
RCLCPP_PUBLIC
explicit TimePoint(uint32_t reference_time, uint32_t remain_time,  uint32_t wait_time,uint32_t last_sample):
reference_time_(reference_time),
remain_time_(remain_time),
wait_time_(wait_time),
last_sample_(last_sample)
{}

RCLCPP_PUBLIC
uint32_t reference_time(){
  return this.reference_time_;
}
RCLCPP_PUBLIC
uint32_t remain_time(){
  std::lock_guard<std::mutex>lock(this.mtx_);
  return this.remain_time_;
}
RCLCPP_PUBLIC
uint32_t wait_time(){
  std::lock_guard<std::mutex>lock(this.mtx_);
  return this.wait_time_;
}
RCLCPP_PUBLIC
uint32_t last_sample(){
  std::lock_guard<std::mutex>lock(this.mtx_);
  return this.last_sample_;
}
RCLCPP_PUBLIC
bool update_time(uint32_t new_time, uint32_t x, MonitorTime target){
  std::lock_guard<std::mutex>lock(this.mtx_);
switch(target){
  MonitorTime::ReferenceTime:{
    this.reference_time_ = (this.reference_time_*(100-x) + new_time*x)/100;
    break;
  }
  MonitorTime::RemainTime:{
    this.remain_time_ = (this.remain_time_*(100-x) + new_time*x)/100;
    break;
  }
  MonitorTime::WaitTime:{
    this.wait_time_ = (this.wait_time_*(100-x) + new_time*x)/100;
    break;
  }
}
return true;
};

private:

std::mutex mtx_;
//history. in millisecond
// usual time from start of the chain till now, for sensor, it is the sample time(time from last sample till now)
uint32_t reference_time_;
// how much free time it could use, it can be a part of the total free time, or equals to the total free time
uint32_t remain_time_;
uint32_t wait_time_;// the usual time to wait for, 0 means no need to wait

uint32_t last_sample_;

#ifdef INTERNEURON_DEBUG
//record each update
#endif
//TODO: more info
}

#endif


namespace node_interfaces
{

/// Pure virtual interface class for the NodeBase part of the Node API.
class NodeBaseInterface
{
public:
  RCLCPP_SMART_PTR_ALIASES_ONLY(NodeBaseInterface)

  RCLCPP_PUBLIC
  virtual
  ~NodeBaseInterface() = default;

  /// Return the name of the node.
  /** \return The name of the node. */
  RCLCPP_PUBLIC
  virtual
  const char *
  get_name() const = 0;

  /// Return the namespace of the node.
  /** \return The namespace of the node. */
  RCLCPP_PUBLIC
  virtual
  const char *
  get_namespace() const = 0;

  /// Return the fully qualified name of the node.
  /** \return The fully qualified name of the node. */
  RCLCPP_PUBLIC
  virtual
  const char *
  get_fully_qualified_name() const = 0;

  /// Return the context of the node.
  /** \return SharedPtr to the node's context. */
  RCLCPP_PUBLIC
  virtual
  rclcpp::Context::SharedPtr
  get_context() = 0;

  /// Return the rcl_node_t node handle (non-const version).
  RCLCPP_PUBLIC
  virtual
  rcl_node_t *
  get_rcl_node_handle() = 0;

  /// Return the rcl_node_t node handle (const version).
  RCLCPP_PUBLIC
  virtual
  const rcl_node_t *
  get_rcl_node_handle() const = 0;

  /// Return the rcl_node_t node handle in a std::shared_ptr.
  /**
   * This handle remains valid after the Node is destroyed.
   * The actual rcl node is not finalized until it is out of scope everywhere.
   */
  RCLCPP_PUBLIC
  virtual
  std::shared_ptr<rcl_node_t>
  get_shared_rcl_node_handle() = 0;

  /// Return the rcl_node_t node handle in a std::shared_ptr.
  /**
   * This handle remains valid after the Node is destroyed.
   * The actual rcl node is not finalized until it is out of scope everywhere.
   */
  RCLCPP_PUBLIC
  virtual
  std::shared_ptr<const rcl_node_t>
  get_shared_rcl_node_handle() const = 0;

  /// Create and return a callback group.
  RCLCPP_PUBLIC
  virtual
  rclcpp::CallbackGroup::SharedPtr
  create_callback_group(
    rclcpp::CallbackGroupType group_type,
    bool automatically_add_to_executor_with_node = true) = 0;

  /// Return the default callback group.
  RCLCPP_PUBLIC
  virtual
  rclcpp::CallbackGroup::SharedPtr
  get_default_callback_group() = 0;

  /// Return true if the given callback group is associated with this node.
  RCLCPP_PUBLIC
  virtual
  bool
  callback_group_in_node(rclcpp::CallbackGroup::SharedPtr group) = 0;

  using CallbackGroupFunction = std::function<void (rclcpp::CallbackGroup::SharedPtr)>;

  /// Iterate over the stored callback groups, calling the given function on each valid one.
  /**
   * This method is called in a thread-safe way, and also makes sure to only call the given
   * function on those items that are still valid.
   *
   * \param[in] func The callback function to call on each valid callback group.
   */
  RCLCPP_PUBLIC
  virtual
  void
  for_each_callback_group(const CallbackGroupFunction & func) = 0;

  /// Return the atomic bool which is used to ensure only one executor is used.
  RCLCPP_PUBLIC
  virtual
  std::atomic_bool &
  get_associated_with_executor_atomic() = 0;

  /// Return a guard condition that should be notified when the internal node state changes.
  /**
   * For example, this should be notified when a publisher is added or removed.
   *
   * \return the GuardCondition if it is valid, else thow runtime error
   */
  RCLCPP_PUBLIC
  virtual
  rclcpp::GuardCondition &
  get_notify_guard_condition() = 0;

  /// Return the default preference for using intra process communication.
  RCLCPP_PUBLIC
  virtual
  bool
  get_use_intra_process_default() const = 0;

  /// Return the default preference for enabling topic statistics collection.
  RCLCPP_PUBLIC
  virtual
  bool
  get_enable_topic_statistics_default() const = 0;

  /// Expand and remap a given topic or service name.
  RCLCPP_PUBLIC
  virtual
  std::string
  resolve_topic_or_service_name(
    const std::string & name, bool is_service, bool only_expand = false) const = 0;

#ifdef INTERNEURON
RCLCPP_PUBLIC
  virtual
  bool init_sensor(const std::string & sensor_name, uint32_t remain_time)= 0;
  RCLCPP_PUBLIC
  virtual
  bool init_publisher(const std::string & topic_name, std::vector<std::string>& sensor_names)= 0;
  RCLCPP_PUBLIC
  virtual
  bool init_subscriber(const std::string & topic_name, std::vector<std::string>& sensor_names)= 0;

  /// sample time for a sensor
  // sample time doesnt belong to a specific pub or sub, it is the start point of a 
  RCLCPP_PUBLIC
  virtual
  bool update_sample_time(const std::string & sensor_name, uint32_t new_time, uint32_t x)= 0;

  /// update publish moment
  //
  RCLCPP_PUBLIC
  virtual
  bool update_pub_time(const std::string & topic_name,const std::string & sensor_name, uint32_t new_time, uint32_t x) = 0;

  /// update receive moment
  //
  RCLCPP_PUBLIC
  virtual
  bool update_rec_time(const std::string & topic_name,const std::string & sensor_name, uint32_t new_time,uint32_t x) = 0;

  /// update start moment of callback
  //
  RCLCPP_PUBLIC
  virtual
  bool update_callback_time(const std::string & topic_name,const std::string & sensor_name, uint32_t new_time, uint32_t x) = 0;
#endif
};

}  // namespace node_interfaces
}  // namespace rclcpp

#endif  // RCLCPP__NODE_INTERFACES__NODE_BASE_INTERFACE_HPP_
