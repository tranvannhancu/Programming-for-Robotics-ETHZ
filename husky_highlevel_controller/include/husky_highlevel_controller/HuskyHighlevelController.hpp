#pragma once

#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <sensor_msgs/Imu.h>
#include <geometry_msgs/Twist.h>
#include <visualization_msgs/Marker.h>
#include <std_srvs/SetBool.h>

namespace husky_highlevel_controller {

/*!
 * Class containing the Husky Highlevel Controller
 */
class HuskyHighlevelController {
 public:
  /*!
   * Constructor.
   */
  HuskyHighlevelController(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~HuskyHighlevelController();

 private:
  ros::NodeHandle nodeHandle_;
  ros::Subscriber subscriber_;
  ros::Subscriber subscriber_IMU_;
  ros::Publisher publisher_;
  ros::Publisher publisher_IMU_;
  ros::Publisher vis_pub_;
  ros::ServiceServer server_;
  ros::ServiceClient client_;

  // variables
  bool pause;
  std_srvs::SetBool service_;

  // parameters
  float p_gain;
  float x_dot;
  float threshold;

  void topicCallback(const sensor_msgs::LaserScan::ConstPtr& msg);
  void topicCallback_IMU(const sensor_msgs::Imu::ConstPtr& msg);
  bool serviceCallback(std_srvs::SetBool::Request& request,
                       std_srvs::SetBool::Response& response);
};

} /* namespace */
