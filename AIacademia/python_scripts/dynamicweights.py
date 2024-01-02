# this function helps calculate final weights for recommendations

def assign_dynamic_weights(user_ambitions, user_activities):
    # Measure the length of user input
    len_ambitions = len(user_ambitions.split())
    len_activities = len(user_activities.split())

    # Normalize the lengths to sum to 1
    total_len = len_ambitions + len_activities
    weight_ambitions = len_ambitions / total_len if total_len > 0 else 0.5
    weight_activities = len_activities / total_len if total_len > 0 else 0.5

    # Adjust the weights if necessary
    # Example: Increase the weight for objectives if ambitions input is significantly larger
    if weight_ambitions > 0.7:  # Threshold can be adjusted
        weight_combined = (weight_ambitions + weight_activities) / 2
        return weight_ambitions, weight_activities * 0.5, weight_combined * 0.5
    else:
        return weight_ambitions, weight_activities, (weight_ambitions + weight_activities) / 2

# Usage Example
# objective_weight, general_info_weight, combined_weight = assign_dynamic_weights(user_ambitions, user_activities)

# # Calculate total similarity with dynamically assigned weights
# combined_total_similarity = (np.array(Objective_Similarity) * objective_weight +
#                              np.array(General_Info_Similarity) * general_info_weight +
#                              np.array(Combined_Similarity) * combined_weight)
